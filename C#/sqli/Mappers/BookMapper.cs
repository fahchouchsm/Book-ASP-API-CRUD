using sqli.DTO;
using sqli.Model;

namespace sqli.Mappers
{
    public class BookMapper
    {
        public static Model.Book toEntity(AddBoookDTO dto)
        {
            return new Model.Book
            {
                title = dto.title,
                author = dto.author,
                ISBN = dto.ISBN,
                nbdisp = dto.nbrDisp,
                publishDate = dto.publishDate
            };
        }

        public static Model.Book toEntity(ModifyDTO dto)
        {
            return new Model.Book
            {
                title = dto.title,
                author = dto.author,
                ISBN = dto.ISBN,
                nbdisp = dto.nbrDisp,
                publishDate = dto.publishDate
            };
        }
    }
}
