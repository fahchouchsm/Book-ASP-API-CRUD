# Book Management API

A simple RESTful API built with ASP.NET Core for managing a collection of books. This project demonstrates basic CRUD operations with in-memory data storage.

## 🚀 Technologies

- **.NET 10**
- **C# 14.0**
- **ASP.NET Core Web API**

## 📋 Features

- Create new books
- Retrieve all books
- Retrieve a specific book by ID
- Update book information
- Delete books
- DTO pattern implementation
- Model mapping
- In-memory data storage

## 🏗️ Project Structure

```
sqli/
├── Controllers/
│   └── BookController.cs      # API endpoints
├── Model/
│   └── Book.cs                # Book entity model
├── DTO/
│   ├── AddBoookDTO.cs         # DTO for creating books
│   └── ModifyDTO.cs           # DTO for updating books
└── Mappers/
    └── BookMapper.cs          # Entity-DTO mapping logic
```

## 🔌 API Endpoints

### Create a Book
```http
POST /book
Content-Type: application/json

{
  "title": "Book Title",
  "author": "Author Name",
  ...
}
```

### Get All Books
```http
GET /book
```

### Get Book by ID
```http
GET /book/{id}
```

### Update a Book
```http
PATCH /book/{id}
Content-Type: application/json

{
  "title": "Updated Title",
  "author": "Updated Author",
  ...
}
```

### Delete a Book
```http
DELETE /book/{id}
```

## 🛠️ Getting Started

### Prerequisites

- [.NET 10 SDK](https://dotnet.microsoft.com/download)

### Installation

1. Clone the repository
   ```bash
   git clone <repository-url>
   cd sqli
   ```

2. Restore dependencies
   ```bash
   dotnet restore
   ```

3. Run the application
   ```bash
   dotnet run
   ```

4. The API will be available at `https://localhost:<port>` (check console output for exact port)

## 📝 Notes

- This application uses **in-memory storage**. Data will be lost when the application stops.
- Auto-incrementing IDs are generated for new books.
- Model validation is enforced through DTOs.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

## 📄 License

This project is for educational purposes.
