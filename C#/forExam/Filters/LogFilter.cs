using System.Runtime.InteropServices;
using forExam.Services.Session;
using Microsoft.AspNetCore.Mvc.Filters;

namespace forExam.Filters
{
    public class LogFilter : ActionFilterAttribute
    {

        public override void OnActionExecuted(ActionExecutedContext context)
        {
            base.OnActionExecuted(context);


        }
    }
}