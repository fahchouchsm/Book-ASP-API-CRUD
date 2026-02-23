using System.ComponentModel.DataAnnotations;

namespace forExam.ViewModels
{
    public class LoginVM
    {
        [Required]
        [StringLength(50, MinimumLength = 3)]
        [DataType(DataType.EmailAddress)]
        public string email { get; set; }
        [Required]
        [StringLength(50, MinimumLength = 3)]
        [DataType(DataType.Password)]
        public string password { get; set; }
    }
}