using forExam.Models;

namespace forExam.Repository.UserRepo
{
    public interface IUserRepository
    {
        public User getByEmail(string email);

    }
}