using System.ComponentModel.DataAnnotations;

namespace sqli.DTO
{
    public class AddBoookDTO
    {
        [Required]
        [StringLength(100)]
        public string title { get; set; }

        [Required]
        [StringLength(100)]
        public string author { get; set; }

        [Required]
        [StringLength(100)]
        public string description { get; set; }

        [Required]
        [DataType(DataType.Date)]
        public DateOnly publishDate { get; set; }

        [Required]
        [Range(1, long.MaxValue)]
        public long ISBN { get; set; }

        [Required]
        [Range(0, int.MaxValue)]
        public int nbrDisp { get; set; }

    }
}
