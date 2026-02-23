using System.Text;

namespace forExam.Services.FileLogger
{
    public class FileLogger :IFileLogger
    {
        private readonly string dirPath = Path.Combine(Directory.GetCurrentDirectory(), "logs");
        private readonly string filePath;

        public FileLogger()
        {
            if (!Directory.Exists("logs"))
            {
                Directory.CreateDirectory("logs");
            }

            filePath = Path.Combine(dirPath, "actions.log");
            if (!File.Exists(filePath))
            {
                File.Create(filePath);
            }
        }

        public void log(string msg)
        {
            File.AppendAllText(filePath, msg);
        }
    }
}