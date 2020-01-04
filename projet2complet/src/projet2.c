/*
 * projet2.c
 *
 *  Created on: 26 nov. 2019
 *      Author: mathis
 */


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

#include "bi.h"

unsigned char moyenne(unsigned char cBleu, unsigned char cVert, unsigned char cRouge)
{
	return (cBleu/3+cVert/3+cRouge/3);
}

	int main()
		{
		int Image1, Image2, G;
		unsigned char buffer[3];
		structImg ABC;


		if((Image1=open("Tux.bmp",O_RDWR))==-1)
			{
			printf("Erreur d'ouverture du fichier: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
			}
		else
			{
			printf("ouverture réussie\n");
			read(Image1,&ABC,sizeof(structImg));
			printf("signature est : %x\nTaille du fichier est : %x\nReserve est : %x\nOffset est : %x\nImgDebut est : %x\nImgLargeur est : %x\nImgHauteur est : %x\nPlan est : %x\nProfondeur couleur est : %x\nCompression est : %x\nImgTaille est : %x\nRésolution horizontale est : %x\nRésolution verticale est : %x\nCouleurs palette est : %x\nCouleurs importante est : %x\n", ABC.signature, ABC.taille_fichier, ABC.reserve, ABC.offset, ABC.img_Debut, ABC.img_Largeur,ABC.img_Hauteur, ABC.plan, ABC.profondeur_couleur, ABC.compression, ABC.img_Taille, ABC.resolution_H, ABC.resolution_V, ABC.couleurs_palette, ABC.couleurs_importantes);

			Image2 = open("Tux_M.bmp", O_CREAT|O_RDWR);
			if (Image2!=-1) {
				write(Image2,&ABC,sizeof(structImg));
				for (int i=0; i<(ABC.offset-sizeof(structImg)); i++)
				{
					read(Image1, buffer, 1);
					write(Image2, buffer, 1);
				}
				//lseek(Image1, ABC.offset,0);
				while(read(Image1, buffer, 3)==3)
						{
						G = moyenne(buffer[0], buffer[1], buffer[2]);
						if(G>=127)
							{
							buffer[0]=G; buffer[1]=G; buffer[2]=G;
							}
						else
						{
							buffer[0]=G; buffer[1]=G; buffer[2]=G;  //oxff
						}
						write(Image2, buffer, 3);
						}

				//write(Image2, buffer,sizeof(structImg));
				close (Image2);
				}
			else
				{
				printf("Ouverture en écriture unmöglish !!");
				}


			close (Image1);
			}
			return EXIT_SUCCESS;

			}
