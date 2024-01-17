/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TD_COMMON_TOKEN_H_
#define _TD_COMMON_TOKEN_H_


#define TK_OR                               1
#define TK_AND                              2
#define TK_UNION                            3
#define TK_ALL                              4
#define TK_MINUS                            5
#define TK_EXCEPT                           6
#define TK_INTERSECT                        7
#define TK_NK_BITAND                        8
#define TK_NK_BITOR                         9
#define TK_NK_LSHIFT                       10
#define TK_NK_RSHIFT                       11
#define TK_NK_PLUS                         12
#define TK_NK_MINUS                        13
#define TK_NK_STAR                         14
#define TK_NK_SLASH                        15
#define TK_NK_REM                          16
#define TK_NK_CONCAT                       17
#define TK_CREATE                          18
#define TK_ACCOUNT                         19
#define TK_NK_ID                           20
#define TK_PASS                            21
#define TK_NK_STRING                       22
#define TK_ALTER                           23
#define TK_PPS                             24
#define TK_TSERIES                         25
#define TK_STORAGE                         26
#define TK_STREAMS                         27
#define TK_QTIME                           28
#define TK_DBS                             29
#define TK_USERS                           30
#define TK_CONNS                           31
#define TK_STATE                           32
#define TK_NK_COMMA                        33
#define TK_HOST                            34
#define TK_USER                            35
#define TK_ENABLE                          36
#define TK_NK_INTEGER                      37
#define TK_SYSINFO                         38
#define TK_ADD                             39
#define TK_DROP                            40
#define TK_GRANT                           41
#define TK_ON                              42
#define TK_TO                              43
#define TK_REVOKE                          44
#define TK_FROM                            45
#define TK_SUBSCRIBE                       46
#define TK_READ                            47
#define TK_WRITE                           48
#define TK_NK_DOT                          49
#define TK_WITH                            50
#define TK_DNODE                           51
#define TK_PORT                            52
#define TK_DNODES                          53
#define TK_RESTORE                         54
#define TK_NK_IPTOKEN                      55
#define TK_FORCE                           56
#define TK_UNSAFE                          57
#define TK_LOCAL                           58
#define TK_QNODE                           59
#define TK_BNODE                           60
#define TK_SNODE                           61
#define TK_MNODE                           62
#define TK_VNODE                           63
#define TK_DATABASE                        64
#define TK_USE                             65
#define TK_FLUSH                           66
#define TK_TRIM                            67
#define TK_COMPACT                         68
#define TK_IF                              69
#define TK_NOT                             70
#define TK_EXISTS                          71
#define TK_BUFFER                          72
#define TK_CACHEMODEL                      73
#define TK_CACHESIZE                       74
#define TK_COMP                            75
#define TK_DURATION                        76
#define TK_NK_VARIABLE                     77
#define TK_MAXROWS                         78
#define TK_MINROWS                         79
#define TK_KEEP                            80
#define TK_PAGES                           81
#define TK_PAGESIZE                        82
#define TK_TSDB_PAGESIZE                   83
#define TK_PRECISION                       84
#define TK_REPLICA                         85
#define TK_VGROUPS                         86
#define TK_SINGLE_STABLE                   87
#define TK_RETENTIONS                      88
#define TK_SCHEMALESS                      89
#define TK_WAL_LEVEL                       90
#define TK_WAL_FSYNC_PERIOD                91
#define TK_WAL_RETENTION_PERIOD            92
#define TK_WAL_RETENTION_SIZE              93
#define TK_WAL_ROLL_PERIOD                 94
#define TK_WAL_SEGMENT_SIZE                95
#define TK_STT_TRIGGER                     96
#define TK_TABLE_PREFIX                    97
#define TK_TABLE_SUFFIX                    98
#define TK_KEEP_TIME_OFFSET                99
#define TK_NK_COLON                       100
#define TK_BWLIMIT                        101
#define TK_START                          102
#define TK_TIMESTAMP                      103
#define TK_END                            104
#define TK_TABLE                          105
#define TK_NK_LP                          106
#define TK_NK_RP                          107
#define TK_STABLE                         108
#define TK_COLUMN                         109
#define TK_MODIFY                         110
#define TK_RENAME                         111
#define TK_TAG                            112
#define TK_SET                            113
#define TK_NK_EQ                          114
#define TK_USING                          115
#define TK_TAGS                           116
#define TK_BOOL                           117
#define TK_TINYINT                        118
#define TK_SMALLINT                       119
#define TK_INT                            120
#define TK_INTEGER                        121
#define TK_BIGINT                         122
#define TK_FLOAT                          123
#define TK_DOUBLE                         124
#define TK_BINARY                         125
#define TK_NCHAR                          126
#define TK_UNSIGNED                       127
#define TK_JSON                           128
#define TK_VARCHAR                        129
#define TK_MEDIUMBLOB                     130
#define TK_BLOB                           131
#define TK_VARBINARY                      132
#define TK_GEOMETRY                       133
#define TK_DECIMAL                        134
#define TK_COMMENT                        135
#define TK_MAX_DELAY                      136
#define TK_WATERMARK                      137
#define TK_ROLLUP                         138
#define TK_TTL                            139
#define TK_SMA                            140
#define TK_DELETE_MARK                    141
#define TK_FIRST                          142
#define TK_LAST                           143
#define TK_SHOW                           144
#define TK_PRIVILEGES                     145
#define TK_DATABASES                      146
#define TK_TABLES                         147
#define TK_STABLES                        148
#define TK_MNODES                         149
#define TK_QNODES                         150
#define TK_FUNCTIONS                      151
#define TK_INDEXES                        152
#define TK_ACCOUNTS                       153
#define TK_APPS                           154
#define TK_CONNECTIONS                    155
#define TK_LICENCES                       156
#define TK_GRANTS                         157
#define TK_QUERIES                        158
#define TK_SCORES                         159
#define TK_TOPICS                         160
#define TK_VARIABLES                      161
#define TK_CLUSTER                        162
#define TK_BNODES                         163
#define TK_SNODES                         164
#define TK_TRANSACTIONS                   165
#define TK_DISTRIBUTED                    166
#define TK_CONSUMERS                      167
#define TK_SUBSCRIPTIONS                  168
#define TK_VNODES                         169
#define TK_ALIVE                          170
#define TK_VIEWS                          171
#define TK_VIEW                           172
#define TK_COMPACTS                       173
#define TK_NORMAL                         174
#define TK_CHILD                          175
#define TK_LIKE                           176
#define TK_TBNAME                         177
#define TK_QTAGS                          178
#define TK_AS                             179
#define TK_SYSTEM                         180
#define TK_INDEX                          181
#define TK_FUNCTION                       182
#define TK_INTERVAL                       183
#define TK_COUNT                          184
#define TK_LAST_ROW                       185
#define TK_META                           186
#define TK_ONLY                           187
#define TK_TOPIC                          188
#define TK_CONSUMER                       189
#define TK_GROUP                          190
#define TK_DESC                           191
#define TK_DESCRIBE                       192
#define TK_RESET                          193
#define TK_QUERY                          194
#define TK_CACHE                          195
#define TK_EXPLAIN                        196
#define TK_ANALYZE                        197
#define TK_VERBOSE                        198
#define TK_NK_BOOL                        199
#define TK_RATIO                          200
#define TK_NK_FLOAT                       201
#define TK_OUTPUTTYPE                     202
#define TK_AGGREGATE                      203
#define TK_BUFSIZE                        204
#define TK_LANGUAGE                       205
#define TK_REPLACE                        206
#define TK_STREAM                         207
#define TK_INTO                           208
#define TK_PAUSE                          209
#define TK_RESUME                         210
#define TK_TRIGGER                        211
#define TK_AT_ONCE                        212
#define TK_WINDOW_CLOSE                   213
#define TK_IGNORE                         214
#define TK_EXPIRED                        215
#define TK_FILL_HISTORY                   216
#define TK_UPDATE                         217
#define TK_SUBTABLE                       218
#define TK_UNTREATED                      219
#define TK_KILL                           220
#define TK_CONNECTION                     221
#define TK_TRANSACTION                    222
#define TK_BALANCE                        223
#define TK_VGROUP                         224
#define TK_LEADER                         225
#define TK_MERGE                          226
#define TK_REDISTRIBUTE                   227
#define TK_SPLIT                          228
#define TK_DELETE                         229
#define TK_INSERT                         230
#define TK_NULL                           231
#define TK_NK_QUESTION                    232
#define TK_NK_ALIAS                       233
#define TK_NK_ARROW                       234
#define TK_ROWTS                          235
#define TK_QSTART                         236
#define TK_QEND                           237
#define TK_QDURATION                      238
#define TK_WSTART                         239
#define TK_WEND                           240
#define TK_WDURATION                      241
#define TK_IROWTS                         242
#define TK_ISFILLED                       243
#define TK_CAST                           244
#define TK_NOW                            245
#define TK_TODAY                          246
#define TK_TIMEZONE                       247
#define TK_CLIENT_VERSION                 248
#define TK_SERVER_VERSION                 249
#define TK_SERVER_STATUS                  250
#define TK_CURRENT_USER                   251
#define TK_CASE                           252
#define TK_WHEN                           253
#define TK_THEN                           254
#define TK_ELSE                           255
#define TK_BETWEEN                        256
#define TK_IS                             257
#define TK_NK_LT                          258
#define TK_NK_GT                          259
#define TK_NK_LE                          260
#define TK_NK_GE                          261
#define TK_NK_NE                          262
#define TK_MATCH                          263
#define TK_NMATCH                         264
#define TK_CONTAINS                       265
#define TK_IN                             266
#define TK_JOIN                           267
#define TK_INNER                          268
#define TK_SELECT                         269
#define TK_NK_HINT                        270
#define TK_DISTINCT                       271
#define TK_WHERE                          272
#define TK_PARTITION                      273
#define TK_BY                             274
#define TK_SESSION                        275
#define TK_STATE_WINDOW                   276
#define TK_EVENT_WINDOW                   277
#define TK_COUNT_WINDOW                   278
#define TK_SLIDING                        279
#define TK_FILL                           280
#define TK_VALUE                          281
#define TK_VALUE_F                        282
#define TK_NONE                           283
#define TK_PREV                           284
#define TK_NULL_F                         285
#define TK_LINEAR                         286
#define TK_NEXT                           287
#define TK_HAVING                         288
#define TK_RANGE                          289
#define TK_EVERY                          290
#define TK_ORDER                          291
#define TK_SLIMIT                         292
#define TK_SOFFSET                        293
#define TK_LIMIT                          294
#define TK_OFFSET                         295
#define TK_ASC                            296
#define TK_NULLS                          297
#define TK_ABORT                          298
#define TK_AFTER                          299
#define TK_ATTACH                         300
#define TK_BEFORE                         301
#define TK_BEGIN                          302
#define TK_BITAND                         303
#define TK_BITNOT                         304
#define TK_BITOR                          305
#define TK_BLOCKS                         306
#define TK_CHANGE                         307
#define TK_COMMA                          308
#define TK_CONCAT                         309
#define TK_CONFLICT                       310
#define TK_COPY                           311
#define TK_DEFERRED                       312
#define TK_DELIMITERS                     313
#define TK_DETACH                         314
#define TK_DIVIDE                         315
#define TK_DOT                            316
#define TK_EACH                           317
#define TK_FAIL                           318
#define TK_FILE                           319
#define TK_FOR                            320
#define TK_GLOB                           321
#define TK_ID                             322
#define TK_IMMEDIATE                      323
#define TK_IMPORT                         324
#define TK_INITIALLY                      325
#define TK_INSTEAD                        326
#define TK_ISNULL                         327
#define TK_KEY                            328
#define TK_MODULES                        329
#define TK_NK_BITNOT                      330
#define TK_NK_SEMI                        331
#define TK_NOTNULL                        332
#define TK_OF                             333
#define TK_PLUS                           334
#define TK_PRIVILEGE                      335
#define TK_RAISE                          336
#define TK_RESTRICT                       337
#define TK_ROW                            338
#define TK_SEMI                           339
#define TK_STAR                           340
#define TK_STATEMENT                      341
#define TK_STRICT                         342
#define TK_STRING                         343
#define TK_TIMES                          344
#define TK_VALUES                         345
#define TK_VARIABLE                       346
#define TK_WAL                            347


#define TK_NK_SPACE         600
#define TK_NK_COMMENT       601
#define TK_NK_ILLEGAL       602
#define TK_NK_HEX           603  // hex number  0x123
#define TK_NK_OCT           604  // oct number
#define TK_NK_BIN           605  // bin format data 0b111
#define TK_BATCH_SCAN       606
#define TK_NO_BATCH_SCAN    607
#define TK_SORT_FOR_GROUP   608
#define TK_PARTITION_FIRST  609


#define TK_NK_NIL 65535

#endif /*_TD_COMMON_TOKEN_H_*/
