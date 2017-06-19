AUX_SOURCE_DIRECTORY(. DIR_MYSQL_SRCS)


ADD_LIBRARY ( encapsulation_mysql SHARED ${DIR_MYSQL_SRCS})
TARGET_LINK_LIBRARIES(encapsulation_mysql mysqlclient)
