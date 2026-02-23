using forExam.Data;
using forExam.Models;
using MySqlConnector;

namespace forExam.Repository.ProductRepo
{
    public class ProductRepository:IProductRepository
    {
        private readonly ISqlDb db;

        public ProductRepository(ISqlDb db)
        {
            this.db = db;
        }

        public List<Product> GetAllProducts()
        {
            using MySqlConnection conn = db.CreateConnection();
            conn.Open();
            string sql = "SELECT * FROM product";
            using MySqlCommand cmd = new MySqlCommand(sql, conn);
            using MySqlDataReader reader = cmd.ExecuteReader();
            List<Product> list = new List<Product>();
            if (reader.Read())
            {
                list.Add(new Product
                {
                    id = reader.GetInt32("id"),
                    name = reader.GetString("name"),
                    price = reader.GetDecimal("price")
                });
            }

            return list;
        }

        public Product GetById(int id)
        {
            using MySqlConnection conn = db.CreateConnection();
            conn.Open();
            string sql = @"SELECT * FROM product WHERE id = @id";
            using MySqlCommand cmd = new MySqlCommand(sql, conn);
            cmd.Parameters.AddWithValue("@id", id);
            using MySqlDataReader reader = cmd.ExecuteReader();

            if (reader.Read())
            {
                return new Product
                {
                    id = reader.GetInt32("id"),
                    name = reader.GetString("name"),
                    price = reader.GetDecimal("price")
                };
            }

            return null;
        }
    }
}