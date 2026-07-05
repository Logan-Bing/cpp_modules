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
		 * @brief Constructeur par default pour la horde.
		 */
		Zombie(void);

		/**
		 * @brief Construit un zombie.
		 * @param name Le nom à attribuer au zombie.
		 */
		Zombie(const std::string& name);

		/**
		 * @brief Annonce le nom du zombie.
		*/
		void	announce(void);
		void	setName(const std::string& name);
};

void randomChump( std::string name );

/**
 * @brief Retourne un Zombie stocké sur la heap
 */
Zombie* newZombie( std::string name );

/**
 * @brief Alloue un tableau de N Zombie, assigne le meme nom pour chaque
 * et retourne l'adrese du premier zombie.
 */
Zombie* zombieHorde(int N, std::string name);

#endif
