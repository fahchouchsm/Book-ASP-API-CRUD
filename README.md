# Book ASP API CRUD

A simple ASP.NET Core Web API for managing books with full CRUD operations. Built with Entity Framework Core.

---

## Features

- Create, Read, Update, Delete books
- RESTful API design
- Swagger UI for testing

---

## Built With

- ASP.NET Core
- Entity Framework Core
- SQL Server (or other via connection string)

---

## Getting Started

# Clone the repository
git clone https://github.com/fahchouchsm/Book-ASP-API-CRUD.git

# Navigate into project
cd Book-ASP-API-CRUD

# Update the database connection in appsettings.json
# (Edit the connection string as needed)

# Apply migrations
dotnet ef migrations add Initial
dotnet ef database update

# Run the API
dotnet run

---

## API Endpoints

# Get all books
GET /api/books

# Get book by ID
GET /api/books/{id}

# Add a new book
POST /api/books

# Update a book
PUT /api/books/{id}

# Delete a book
DELETE /api/books/{id}

---

## Notes

# Keep business logic in services, not controllers
# Use DTOs and validation for input
# Use async methods for performance
