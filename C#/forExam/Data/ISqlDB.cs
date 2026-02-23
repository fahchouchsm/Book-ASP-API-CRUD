using MySqlConnector;

namespace forExam.Data
{
    public interface ISqlDb
    {
       public MySqlConnection CreateConnection();
       public MySqlCommand CreateCommand(string sql, MySqlConnection conn);
    }
}