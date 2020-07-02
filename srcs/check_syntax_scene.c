/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:58:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/02 18:57:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"



/*static bool check_elem_list(char *scene_line)
{
	if ()
	}*/

bool check_syntax_scene(char *scene_file)
{
	//comprobar si el fichero abre
	//comprobar la informacion del fichero
	//comprobar casos concretos (resolucion y ambiente no duplican...)
	int fd;
	int i;
	char *line;
	char **scene_line;

	i = 0;
	if ((fd = open(scene_file, O_RDONLY) < 0))
		{
			printf("error al abrir el fichero.\n");
			return (false);
		}
	while (get_next_line(fd, &line) == 1)
		{
		 if (!(scene_line = ft_split(line, ' ')))
				return (false);
		 while (scene_line[i])
				{
					printf("%s\n", scene_line[1]);
					i++;
					}
			printf("====\n");
		}
	return (true);
}