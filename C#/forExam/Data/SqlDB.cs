using Microsoft.Data.SqlClient;
using MySqlConnector;

namespace forExam.Data
{
    public class SqlDB: ISqlDb
    {
        private readonly string conn;

        public SqlDB(IConfiguration config)
        {
            conn = config.GetConnectionString("Default");
        }

        public MySqlConnection CreateConnection()
        {
            return new MySqlConnection(conn);
        }

        public MySqlCommand CreateCommand(string sql, MySqlConnection conn)
        {
            return new MySqlCommand(sql, conn);
        }
    }
}