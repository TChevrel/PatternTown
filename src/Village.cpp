#include "Village.h"

#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <iostream>

using namespace std;



Village::Village() : population_(0) {}


Village::~Village() {
	for (size_t i=0 ; i<villageois_.size() ; ++i ) {
			delete villageois_[i];
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// renvoie vrai si id est present dans le vector de batiments
bool Village::existe_Batiment( int id ) {
	for( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return true;
		}
	}
	return false;
}


// renvoie vrai si id est present dans le vector de villageois
bool Village::existe_Villageois( int id ) {
	for( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return true;
		}
	}
	return false;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne le villageois correspondant a id
// id doit exister dans le vector !
Villageois* Village::get_Villageois( int id ) {
	for ( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return v;
		}
	}
	return 0;
}


// retourne le batiment correspondant a�id
// id doit exister dans le vector !
Batiment* Village::get_Batiment( int id ) {
	for ( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return b;
		}
	}
	return 0;
}


// retourne la quantit� de la ressource id
int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}

// retourne les ressources
Ressource* Village::get_Ressources() {
	return &ressources_;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// ajoute un villageois
// si d�ja present, ne fait rien
void Village::add_Villageois( Villageois* v ) {
	if ( !existe_Villageois( v->get_id() ) ) {
		villageois_.push_back(v);
		++population_;
	}
}


// modifie un villageois (decorator)
// id doit exister dans le vector !
void Village::change_Villageois( Villageois* nv ) {
	int id = nv->get_id();
	villageois_.push_back( nv );
	int i = 0;
	while ( villageois_[i]->get_id() != id ) { ++i; }
	villageois_.erase( villageois_.begin() + i);
}


// ajoute un batiment
// si d�ja present, ne fait rien
void Village::add_Batiments( Batiment* b ) {
	if ( !existe_Batiment( b->get_id() ) ) {
		batiments_.push_back(b);
		++constructions_;
	}
}


// modifie la quantite de la ressource id
void Village::change_Ressource( int id, int quantite ) {
	ressources_.change_Ressource(id,quantite);
}


// supprime le villageois correspondant � id
// si absent, ne fait rien
void Village::remove_Villageois( int id ) {
	for( size_t i=0 ; i<villageois_.size() ; ++i ) {
		if ( villageois_[i]->get_id() == id ) {
			delete villageois_[i];
			villageois_.erase( villageois_.begin() + i );
		}
	}
}


// supprime le batiment correspondant � id
// si absent, ne fait rien
void Village::remove_Batiment( int id ) {
	for( size_t i=0 ; i<batiments_.size() ; ++i ) {
		if ( batiments_[i]->get_id() == id ) {
			delete batiments_[i];
			batiments_.erase( batiments_.begin() + i );
		}
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void Village::afficher_Villageois() {
	for ( Villageois* v : villageois_ ) {
		v->afficher();
	}
}
