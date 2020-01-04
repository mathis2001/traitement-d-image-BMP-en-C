/*
 * bi.h
 *
 *  Created on: 26 nov. 2019
 *      Author: mathis
 */

#pragma pack(push, 2)
typedef struct
	{
		unsigned short signature;
		unsigned int taille_fichier;
		unsigned int reserve;
		unsigned int offset;
		unsigned int img_Debut;
		unsigned int img_Largeur;
		unsigned int img_Hauteur;
		unsigned short plan;
		unsigned short profondeur_couleur;
		unsigned int compression;
		unsigned int img_Taille;
		unsigned int resolution_H;
		unsigned int resolution_V;
		unsigned int couleurs_palette;
		unsigned int couleurs_importantes;

	}structImg;
#pragma pack(pop)
