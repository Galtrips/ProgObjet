#include <cstring>

class Item {

	private:
		char* Nom;
		bool Valid� = false;

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
				setValider(i.Valid�);
			}
			return(*this);
		}

		void Affiche();

};
