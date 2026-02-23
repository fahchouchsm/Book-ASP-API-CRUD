using forExam.Services.Auth;
using forExam.ViewModels;
using Microsoft.AspNetCore.Mvc;

namespace forExam.Controllers
{
    public class LoginController : Controller
    {
        private readonly IAuthService authService;

        public LoginController(IAuthService authService)
        {
            this.authService = authService;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Login(LoginVM vm)
        {
            if (!ModelState.IsValid)
            {
                return View(vm);
            }

            if (authService.Login(vm))
            {
                return RedirectToAction("Index", "Product");
            }
            return View(vm);
        }
    }
}