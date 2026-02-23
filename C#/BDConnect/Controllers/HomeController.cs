using Microsoft.AspNetCore.Mvc;

namespace BDConnect.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Add()
        {
            
            return View();
        }
    }
}
