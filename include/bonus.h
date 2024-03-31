/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:42:50 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/26 17:31:03 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line_bonus.h"
# include "../libft/include/libft.h"
# include <ctype.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_MAX_STRING "2147483647"
# define INT_MIN_STRING "-2147483648"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				real_value;
}					t_stack;

// PARSING
char				**ft_check_numb_arg_bonus(int argc, char **argv);
long				ft_strlen_revised_bonus(char *str);
char				**ft_argv_to_one_line_bonus(char **argv, int argc, int i);
long				ft_atol_bonus(char *str);
int					ft_count_digit_bonus(char **argv);
int					*ft_atoi_tab_bonus(char **tab);

// Memory
void				free_double_tab_char_bonus(char **tab);
void				ft_write_error_bonus(t_stack *a, t_stack *b);
void				free_lists_bonus(t_stack *stack);
void				ft_write_error_na_bonus(void);
void				ft_wait_push_swap(void);
void				ft_exit(void);

// Initialise
t_stack				*ft_initialize_stack_a_bonus(int *tab_int,
						char **tab_string);
void				ft_stack_add_to_back_bonus(t_stack **a, t_stack *new_node);

// UTILS
int					ft_find_size_bonus(char **tab_str);
int					ft_check_sorting_bonus(t_stack **stack);
t_stack				*ft_last_stack_bonus(t_stack *a);
t_stack				*ft_new_node_bonus(int integer);

// ACTIONS
void				ft_push_to_a_bonus(t_stack **a, t_stack **b);
void				ft_push_to_b_bonus(t_stack **b, t_stack **a);
void				ft_rra_bonus(t_stack **stack);
void				ft_rrb_bonus(t_stack **stack);
void				ft_rrr_bonus(t_stack **a, t_stack **b);
void				ft_sa_bonus(t_stack **stack);
void				ft_sb_bonus(t_stack **stack);
void				ft_ss_bonus(t_stack **a, t_stack **b);
void				ft_rr_bonus(t_stack **a, t_stack **b);
void				ft_rb_bonus(t_stack **stack);
void				ft_ra_bonus(t_stack **stack);

#endif