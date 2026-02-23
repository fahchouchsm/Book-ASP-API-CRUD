using Microsoft.AspNetCore.Mvc;
using System.Text.Json;
using tp_1_controller_.data;

namespace tp_1_controller_.Controllers
{
    public class HomeController : Controller
    {
        List<Todo> todos = new List<Todo>();

        public IActionResult Index()
        {
            todos = JsonSerializer.Deserialize<List<Todo>>(HttpContext.Session.GetString("todos") ?? "[]");
            todos.Add(new Todo("Faire les courses", "Acheter du lait, du pain et des œufs", Enum.Status.ToDo, DateTime.Now.AddDays(2)));
            ViewBag.todos = todos;
            return View();
        }



    }
}
