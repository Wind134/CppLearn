#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    MYSQL* conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "Error initializing MySQL: %s\n", mysql_error(conn));
        return 1;
    }

    if (argc != 5)
    {
        printf("Usage: %s <host> <user> <password> <database name>\n", argv[0]);
        exit(1);
    }

    if (mysql_real_connect(conn, argv[1], argv[2], argv[3], argv[4], 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error connecting to MySQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    if (mysql_query(conn, "SELECT * FROM user")) {
        fprintf(stderr, "Error querying MySQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Error storing MySQL result: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}
