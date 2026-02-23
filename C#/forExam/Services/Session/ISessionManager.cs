using System.Text.Json;

namespace forExam.Services.Session
{
    public interface ISessionManager
    {
        public T getFromSession<T>(string sessionName);
        public void setToSession<T>(string sessionName, T value);
        public void setString(string sessionName, string value);
    }
}