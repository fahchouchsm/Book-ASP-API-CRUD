using forExam.ViewModels;

namespace forExam.Services.Auth
{
    public interface IAuthService
    {
        public bool Login(LoginVM vm);
    }
}