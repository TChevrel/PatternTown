#ifndef VILLAGE_H
#define VILLAGE_H

class Villageois;
class Batiment;
#include "Ressource.h"
#include <vector>
#include <string>


class Village {

	private :

		std::string nom_;
		std::vector<Villageois*> villageois_;
		std::vector<Batiment*> batiments_;
		Ressource ressources_;


	public :

		// Constructeurs/Destructeurs
			Village( std::string nom );
			~Village();

		// Testing
			bool existe_Batiment( int id );
			bool existe_Villageois( int id );

		// Getters
			std::string get_Nom();			
			Villageois* get_Villageois( int id );
			Batiment* get_Batiment( int id );
			Ressource* get_Ressources();
			int get_Ressource( int id );
			int get_Population();
			int get_Constructions();


		// Setters
			void add_Villageois( Villageois* v );
			void change_Villageois( Villageois* v );
			void add_Batiments( Batiment* b );
			void change_Ressource( int id, int quantite );
			void remove_Villageois( int id );
			void remove_Batiment( int id );

		void afficher_Villageois();


};

#endif
