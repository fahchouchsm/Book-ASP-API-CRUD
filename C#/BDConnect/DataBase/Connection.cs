using MySql.Data.MySqlClient;

namespace BDConnect.DataBase
{
    public class Connection
    {
        private const string ConnectionString = "Server=localhost;Port=3306;Database=MyDb;User=root;Password=admin;";

        public Connection()
        {
            MySqlConnection conn = new MySqlConnection(ConnectionString);
            conn.Open();
        }
    }
}
