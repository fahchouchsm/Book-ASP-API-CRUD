using forExam.Models;

namespace forExam.Repository.ProductRepo
{
    public interface IProductRepository
    {
        public List<Product> GetAllProducts();
        public Product GetById(int id);
    }
}

