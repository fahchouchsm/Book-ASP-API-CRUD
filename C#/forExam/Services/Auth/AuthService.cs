using forExam.Models;
using forExam.Repository.UserRepo;
using forExam.Services.Session;
using forExam.ViewModels;

namespace forExam.Services.Auth
{
    public class AuthService: IAuthService
    {
        private readonly ISessionManager sessionManager;
        private readonly IUserRepository userRepository;

        public AuthService(ISessionManager sessionManager, IUserRepository userRepository)
        {
            this.sessionManager = sessionManager;
            this.userRepository = userRepository;
        }

        public bool Login(LoginVM vm)
        {
            User user = userRepository.getByEmail(vm.email);
            if (user == null) return false;
            if (user.email == vm.email && user.password == vm.password)
            {
                sessionManager.setString("auth" , "");
                return true;
            }

            return false;
        }
    }
}