/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:11:51 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/21 15:38:42 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				cost;
	int				index;
	int				real_value;
	int				reworked_value;
	int				percentile;
	int				rank;
	int				flag_dealt;
	int				flag_above_median;
	int				place;
	struct s_stack	*asso_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

typedef struct s_info
{
	int				max;
	int				size;
	int				max_reworked;
	int				max_rank_in_b;
	int				number_of_node_current_rank;
	int				one_third;
	int				two_third;
	int				current_size_a;
	int				current_size_b;
	int				current_max_a;
	int				current_max_b;
	int				current_min_a;
	int				current_min_b;
	struct s_stack	*cheapest_node;
	int				median_a;
	int				median_b;
	int				max_rank;

}					t_info;

// PARSING
long				ft_atol(char *str);
int					ft_count_digit(char **argv);
char				*ft_strjoinfree(char *s1, char *s2);
char				**ft_argv_to_one_line(char **argv, int argc, int i);
long				ft_strlen_revised(char *str);
int					ft_check_argv2(char **argv);
char				**ft_check_numb_arg(int argc, char **argv);

// INITIALIZE
t_info				*ft_initialize_info(char **tab_string, int *tab_int);
void				ft_reset_flag_dealt(t_stack **a);
void				ft_add_information_stack_a(t_stack **a, t_info *info);
t_stack				*ft_initialize_stack_a(int *tab_int, t_info *info);
void				ft_add_flag_median_all_a(t_stack **stack, t_info *info);
void				ft_add_flag_median_all_b(t_stack **stack, t_info *info);
void				ft_find_place_in_stack(t_stack **stack, t_info *info,
						int flag);
void				ft_recalculate_percentile(t_stack **a, t_info *info);

// MEMORY
void				free_lists(t_stack *stack);
void				ft_free_all(t_info *info, t_stack *a);
void				free_double_tab_char(char **tab);
void				ft_write_error(void);

// SORTING
void				ft_sorting_stack(t_stack **a, t_stack **b, t_info *info);
int					ft_check_sorting_index(t_stack *stack);
int					ft_find_size(char **tab_str);
void				ft_perform_action_sort_stack(t_stack **a, t_stack **b,
						t_info *info, int flag);
void				ft_sort_b(t_stack **b, t_info *info);

// MATH
int					ft_find_temp(t_stack **stack, t_stack *copy_send, int flag);
void				find_node(t_stack *node1, t_stack *node2, int temp,
						int flag);
int					ft_find_max_int_tab(int *tab_int, int size);
int					ft_find_max_list(t_stack **stack);
int					ft_find_min_list(t_stack **stack);
void				ft_calculate_max_rank_in_b(t_stack **b, t_info *info);
int					*ft_atoi_tab(char **tab);

// LIST
t_stack				*ft_find_max_list_address(t_stack **stack);
t_stack				*ft_find_min_list_address(t_stack **stack);
t_stack				*ft_new_node(int integer, int i);
t_stack				*ft_last_stack(t_stack *a);
void				ft_stack_add_to_back(t_stack **a, t_stack *new_node);

// COST CALCUL
void				ft_find_cheapest_node_b(t_stack **b, t_info *info);
void				ft_calculate_cost_and_rank_count_for_a(t_stack **a,
						t_info *info);
void				ft_determine_cost_for_b(t_stack **b, t_info *info);
void				ft_calculate_rank(t_stack **a, t_info *info, int flag);
void				ft_find_asso_node_for_b(t_stack **b, t_stack **a,
						t_info *info, int flag);

// ACTIONS
void				ft_push_to_a(t_stack **a, t_stack **b, t_info *info);
void				ft_push_to_b(t_stack **b, t_stack **a, t_info *info);
void				ft_rra(t_stack **stack, t_info *info);
void				ft_rrb(t_stack **stack, t_info *info);
void				ft_rrr(t_stack **a, t_stack **b, t_info *info);
void				ft_ra(t_stack **stack, t_info *info);
void				ft_rb(t_stack **stack, t_info *info);
void				ft_rr(t_stack **a, t_stack **b, t_info *info);
void				ft_sa(t_stack **stack, t_info *info);
void				ft_sb(t_stack **stack, t_info *info);
void				ft_ss(t_stack **a, t_stack **b, t_info *info);
void				ft_perform_action_cheap_node_a(t_stack **a, t_stack **b,
						t_info *info);
void				ft_perform_action_cheap_node_b(t_stack **a, t_stack **b,
						t_info *info);

#endif