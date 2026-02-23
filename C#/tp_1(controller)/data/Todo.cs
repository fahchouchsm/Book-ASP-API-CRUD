using tp_1_controller_.Enum;

namespace tp_1_controller_.data
{
    public class Todo
    {
        public string Libelle { get; set; }
        public string Description { get; set; }
        public Status Status { get; set; }
        public DateTime DateLimite { get; set; }

        public Todo(string libelle, string description, Status status, DateTime dateLimite)
        {
            Libelle = libelle;
            Description = description;
            Status = status;
            DateLimite = dateLimite;
        }
    }
}
