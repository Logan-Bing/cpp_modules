#include <iostream>
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

/**
 * @brief Représente un zombie identifié par un nom.
 *
 * Chaque zombie porte un nom qui lui est donné à la construction.
 * Utilisée pour illustrer la création d'objets sur la pile et le tas.
 */
class Zombie {

	private:
		/// Nom du zombie, fixé à la construction.
		std::string _name;

	public:
		/**
		 * @brief Construit un zombie.
		 * @param name Le nom à attribuer au zombie.
		 */
		Zombie(const std::string& name);
		~Zombie(void);

		/**
		 * @brief Annonce le nom du zombie.
		*/
		void	announce(void);
};

void randomChump( std::string name );

/**
 * @brief Retourne un Zombie stocké sur la heap
 */
Zombie* newZombie( std::string name );

#endif
