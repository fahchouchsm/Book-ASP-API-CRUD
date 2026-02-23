namespace sqli.Model
{
    public class Book
    {
        public int id { get; set; }
        public string title { get; set; }
        public string author { get; set; }
        public DateOnly publishDate { get; set; }
        public long ISBN { get; set; }
        public int nbdisp { get; set; }

    }
}