

from util.dnodes import *
from util.log import *
from util.sql import *
from util.cases import *
import datetime


class TDTestCase:

    def init(self, conn, logSql):
        tdLog.debug(f"start to excute {__file__}")
        tdSql.init(conn.cursor())
        self.today_date = datetime.datetime.strptime(
            datetime.datetime.now().strftime("%Y-%m-%d"), "%Y-%m-%d")
        self.time_unit = ['b','u','a','s','m','h','d','w']
        self.error_param = ['1.5','abc','!@#','"abc"','today()']
        self.arithmetic_operators = ['+','-','*','/']
        self.relational_operator = ['<','<=','=','>=','>']
        # prepare data
        self.ntbname = 'ntb'
        self.stbname = 'stb'
        self.column_dict = {
            'ts':'timestamp',
            'c1':'int',
            'c2':'float',
            'c3':'double',
            'c4':'timestamp'
        }
        self.tag_dict = {
            't0':'int'
        }
        self.tbnum = 2
        self.tag_values = [
            f'10',
            f'100'
        ]
        self.values_list = [f'now,1,1.55,100.555555,today()',
                        f'now+1d,10,11.11,99.999999,now()',
                        f'today(),3,3.333,333.333333,now()',
                        f'today()-1d,10,11.11,99.999999,now()',
                        f'today()+1d,1,1.55,100.555555,today()']
                       
    def set_create_normaltable_sql(self, ntbname, column_dict):
        column_sql = ''
        for k, v in column_dict.items():
            column_sql += f"{k} {v},"
        create_ntb_sql = f'create table {ntbname} ({column_sql[:-1]})'
        return create_ntb_sql
    def set_create_stable_sql(self,stbname,column_dict,tag_dict):
        column_sql = ''
        tag_sql = ''
        for k,v in column_dict.items():
            column_sql += f"{k} {v},"
        for k,v in tag_dict.items():
            tag_sql += f"{k} {v},"
        create_stb_sql = f'create table {stbname} ({column_sql[:-1]}) tags({tag_sql[:-1]})'
        return create_stb_sql
    def data_check(self,column_dict={},tbname = '',values_list = [],tb_num = 1,tb = 'tb'):
        for k,v in column_dict.items():
            num_up = 0
            num_down = 0
            num_same = 0
            if v.lower() == 'timestamp':
                tdSql.query(f'select {k} from {tbname}')
                for i in tdSql.queryResult:
                    if i[0] > self.today_date:
                        num_up += 1
                    elif i[0] == self.today_date:
                        num_same += 1
                    elif i[0] < self.today_date:
                        num_down += 1
                tdSql.query(f"select today() from {tbname}")
                tdSql.checkRows(len(values_list)*tb_num)
                tdSql.checkData(0, 0, str(self.today_date))
                tdSql.query(f"select * from {tbname} where {k}=today()")
                if tb == 'tb':
                    tdSql.checkRows(num_same*tb_num)
                elif tb == 'stb':
                    tdSql.checkRows(num_same)
                for i in [f'{tbname}',f'db.{tbname}']:
                    for unit in self.time_unit:
                        for symbol in ['+','-']:
                            tdSql.query(f"select today() {symbol}1{unit} from {i}")
                            tdSql.checkRows(len(values_list)*tb_num)
                    for unit in self.error_param:
                        for symbol in self.arithmetic_operators:
                            tdSql.error(f'select today() {symbol}{unit} from {i}')
                    for symbol in self.arithmetic_operators:
                        tdSql.query(f'select now(){symbol}null from {i}')
                        tdSql.checkData(0,0,None)
                    for symbol in self.relational_operator:
                        tdSql.query(f'select * from {i} where {k} {symbol} today()')
                        if symbol == '<' :
                            if tb == 'tb':
                                tdSql.checkRows(num_down*tb_num)
                            elif tb == 'stb':
                                tdSql.checkRows(num_down)
                        elif symbol == '<=':
                            if tb == 'tb':
                                tdSql.checkRows((num_same+num_down)*tb_num)
                            elif tb == 'stb':
                                tdSql.checkRows(num_same+num_down)
                        elif symbol == '=':
                            if tb == 'tb':
                                tdSql.checkRows(num_same*tb_num)
                            elif tb == 'stb':
                                tdSql.checkRows(num_same)
                        elif symbol == '>=':
                            if tb == 'tb':
                                tdSql.checkRows((num_up + num_same)*tb_num)
                            elif tb == 'stb':
                                tdSql.checkRows(num_up + num_same)
                        elif symbol == '>':
                            if tb == 'tb':
                                tdSql.checkRows(num_up*tb_num)
                            elif tb == 'stb':
                                tdSql.checkRows(num_up)
                tdSql.query(f"select today()/0 from {tbname}")
                tdSql.checkRows(len(values_list)*tb_num)
                tdSql.checkData(0,0,None)
                tdSql.query(f"select {k} from {tbname} where {k}=today()")
                if tb == 'tb':
                    tdSql.checkRows(num_same*tb_num)
                    for i in range(num_same*tb_num):
                        tdSql.checkData(i, 0, str(self.today_date))
                elif tb == 'stb':
                    tdSql.checkRows(num_same)
                    for i in range(num_same):
                        tdSql.checkData(i, 0, str(self.today_date))
    def today_check_ntb(self):
        tdSql.prepare()
        tdSql.execute(self.set_create_normaltable_sql(self.ntbname,self.column_dict))
        for i in self.values_list:
            tdSql.execute(
                f'insert into {self.ntbname} values({i})')
        self.data_check(self.column_dict,self.ntbname,self.values_list)
        tdSql.execute('drop database db')
    def today_check_stb_tb(self):
        tdSql.prepare()
        tdSql.execute(self.set_create_stable_sql(self.stbname,self.column_dict,self.tag_dict))
        for i in range(self.tbnum):
            tdSql.execute(f'create table if not exists {self.stbname}_{i} using {self.stbname} tags({self.tag_values[i]})')
            for j in self.values_list:
                tdSql.execute(f'insert into {self.stbname}_{i} values ({j})')
        # check child table
        for i in range(self.tbnum):
            self.data_check(self.column_dict,f'{self.stbname}_{i}',self.values_list)
        # check stable
        self.data_check(self.column_dict,self.stbname,self.values_list,self.tbnum,'stb')
        tdSql.execute('drop database db')

    def run(self):  # sourcery skip: extract-duplicate-method
        
        tdLog.printNoPrefix("==========check today() for normal table ==========")
        self.today_check_ntb()
        tdLog.printNoPrefix("==========check today() for stable and child table==========")
        self.today_check_stb_tb()

    def stop(self):
        tdSql.close()
        tdLog.success(f"{__file__} successfully executed")

tdCases.addLinux(__file__, TDTestCase())
tdCases.addWindows(__file__, TDTestCase())
