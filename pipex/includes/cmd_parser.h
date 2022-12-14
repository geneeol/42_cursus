/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:47:36 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 02:17:05 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PARSER_H
# define CMD_PARSER_H

char	**const	get_paths(char *envp[]);
char	*find_cmd_path(char *cmd, char **paths);

#endif
