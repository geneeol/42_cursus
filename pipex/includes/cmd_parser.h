/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:47:36 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 16:36:19 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PARSER_H
# define CMD_PARSER_H

char	**get_envp_paths(char *envp[]);
char	*find_cmd_path(char *cmd, char **envp_paths);

#endif
