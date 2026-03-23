public class Book extends Product {
    private String author;
    private String isbn;
    private String genre;

    public Book(int code, String description, int price, String author, String isbn, String genre) {
        super(code, description, price);
        this.author = author;
        this.isbn = isbn;
        this.genre = genre;
    }

    public String getAuthor() {
        return this.author;
    }

    public String getIsbn() {
        return this.isbn;
    }

    public String getGenre() {
        return this.genre;
    }
}