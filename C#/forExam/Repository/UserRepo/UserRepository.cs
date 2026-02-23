using System.Data;
using forExam.Data;
using forExam.Models;
using MySqlConnector;

namespace forExam.Repository.UserRepo
{
    public class UserRepository : IUserRepository
    {
        private readonly ISqlDb db;

        public UserRepository(ISqlDb db)
        {
            this.db = db;
        }

        public User getByEmail(string email)
        {
            MySqlConnection conn = db.CreateConnection();
            conn.Open();

            string sql = @"SELECT id, email, password FROM users WHERE email = @email;";
            MySqlCommand cmd = db.CreateCommand(sql, conn);
            cmd.Parameters.AddWithValue("@email", email);

            MySqlDataReader reader = cmd.ExecuteReader();
            if (reader.Read())
            {
                return new User()
                {
                    id = reader.GetInt32("id"),
                    email = reader.GetString("email"),
                    password = reader.GetString("password")
                };
            }

            return null;
        }
    }
}