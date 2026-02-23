class Personne
{
public:
    Personne();
    Personne(const char *, const char *, const int &);
    ~Personne();
    void affiche() const;

private:
    char *nom;
    char *prenom;
    int age;
};