using System.Text.Json;

namespace forExam.Services.Session
{
    public class SessionManager: ISessionManager
    {
        private readonly IHttpContextAccessor httpContextAccessor;

        public SessionManager(IHttpContextAccessor httpContextAccessor)
        {
            this.httpContextAccessor = httpContextAccessor;
        }

        public T getFromSession<T>(string sessionName)
        {
            string json = httpContextAccessor.HttpContext.Session.GetString(sessionName);
            return JsonSerializer.Deserialize<T>(json);
        }

        public void setToSession<T>(string sessionName, T value)
        {
            string json = JsonSerializer.Serialize(value);
            httpContextAccessor.HttpContext.Session.SetString(sessionName, json);
        }

        public void setString(string sessionName, string value)
        {
            httpContextAccessor.HttpContext.Session.SetString(sessionName, value);
        }
    }
}