using Microsoft.AspNetCore.Mvc;

namespace forExam.Controllers
{
    public class ProductController : Controller
    {
        public IActionResult Index()
        {
            HttpContext.Items["hello"] = "hello world";
            return View();
        }


    }
}