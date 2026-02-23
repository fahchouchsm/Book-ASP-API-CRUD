using Microsoft.AspNetCore.Mvc;
using sqli.DTO;
using sqli.Mappers;

namespace sqli.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class BookController : ControllerBase
    {
        private static List<Model.Book> books = new List<Model.Book>();

        [HttpPost]
        public IActionResult addBook([FromBody] AddBoookDTO dto)
        {
            if(!ModelState.IsValid)
            {
                return BadRequest();
            }

            Model.Book book = BookMapper.toEntity(dto);
            if(books.Count == 0)
            {
                book.id = 0;
            } else
            {
            book.id = books.Max(b => b.id) + 1;
            }
            books.Add(book);
            return CreatedAtAction(nameof(getBookById), new { id = book.id }, book);
        }

        [HttpGet]
        public IActionResult getBooks()
        {
            return Ok(books);
        }

        [HttpGet("{id}")]
        public IActionResult getBookById(int id)
        {
            Model.Book? foundBook = books.Find(b => b.id == id);
            if (foundBook == null)
            {
                return NotFound();
            }
            return Ok(foundBook);
        }

        [HttpPatch("{id}")]
        public IActionResult modifyBook(int id, [FromBody] ModifyDTO dto)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest();
            }

            int bookIndex = books.FindIndex(b => b.id == id);
            if (bookIndex == -1)
            {
                return NotFound();
            }
            Model.Book book = books[bookIndex];

            Model.Book newBook = BookMapper.toEntity(dto);
            newBook.id = book.id;
            books[bookIndex] = newBook;
            return Ok(newBook);
        }

        [HttpDelete("{id}")]
        public IActionResult deleteBook(int id)
        {
            Model.Book? book = books.Find(b => b.id == id);
            if(book == null)
            {
                return NotFound();
            }
            books.Remove(book);
            return NoContent();
        }
    }
}
