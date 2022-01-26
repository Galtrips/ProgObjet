#include <cstring>

class Item {

	private:
		char* Nom;
		bool Validé = false;

	public:

		Item();
		Item(const char* n, bool v);
		~Item();

		char* getNom();
		bool getValider();

		void setNom(const char* n);
		void setValider(bool v);

		Item(const Item& i);
		Item& operator =(const Item& i) {
			if (this != &i) {
				setNom(i.Nom);
				setValider(i.Validé);
			}
			return(*this);
		}

		void Affiche();

};
