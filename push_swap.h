/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:00:53 by dwillett          #+#    #+#             */
/*   Updated: 2021/03/18 15:15:45 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct			s_stack
{
	int					content;
	int					color_flag;
	struct s_stack		*next;
}						t_stack;

typedef	struct			s_trash
{
	int					top;
	int					print;
}						t_trash;

typedef	struct			s_bonus
{
	int					debug;
	int					color;
}						t_bonus;

/*
** checker_bonus
*/

void					ft_putnbr_fd_color(int n, int fd);
void					down_flag(t_stack **a, t_stack **b);
void					print_stack_all(t_stack *a, t_stack *b, int flag);
void					print_stack(t_stack *tmp, int flag, int color);
void					ints_collection_bonus(t_stack **a, t_stack **b, \
int flag);
void					init_bonus_struct(t_bonus *bonus, int flag);
int						args_error_check_bonus(char **argv, t_stack **a,
								t_bonus *bonus);
int						args_error_check_extra(char **argv, t_stack **a, \
int *sign_flag, int i);
int						search_for_the_flag(char **argv, int *i);
int						instructions(t_stack **a, t_stack **b, t_list *inst, \
t_bonus bonus);

/*
** checker
*/

t_stack					*ft_lstnew_s(int num);
t_stack					*rotate(t_stack *current);
t_stack					*rev_rotate(t_stack *current);
void					ft_lstadd_back_s(t_stack **head, t_stack *new);
void					ft_lstadd_front_s(t_stack **head, t_stack *new);
void					ft_lstclear_s(t_stack **a);
void					ft_clear(char **tmp);

void					my_exit(t_list **inst, t_stack *a, t_stack *b);
void					result_output(t_stack **a, t_stack **b, t_list **inst);
void					swap(t_stack **current);
void					push(t_stack **src, t_stack **dest);
void					instructions_exec(t_list *inst, t_stack **a, t_stack
**b);
void					swap_and_push_inst(t_list *inst, t_stack **a, t_stack
**b);
void					rotate_inst(t_list **inst, t_stack **a, t_stack **b);
void					rev_rotate_inst(t_list **inst, t_stack **a, t_stack
**b);
int						ft_lstcount(t_stack *a);
int						lst_last_content(t_stack *tmp);
int						sign_check(int *flag, long int num);
int						doubles_check(t_stack *a, int num);
int						isnum_check(char *arg);
int						args_error_check(char **argv, t_stack **a);
int						error_message(t_stack **a, char **tmp);
int						sort_check(t_stack *a);
int						check_str(char *str);
int						instructions_check(t_list **inst);
int						inst_collection(t_list **inst);
int						get_next_line(char **line);
int						gnl_clear(char *line, t_list **inst);

/*
** push_swap
*/

t_stack					*copy(t_stack *ref);
void					call_for_clear(t_stack *a, t_stack *b);
void					choose_sort(t_stack *a, t_stack *b);
void					small_sorts(t_stack *a, t_stack *b);
int						find_index(int array[4]);
int						arg_collection(char **argv, t_stack **a);

int						call_swap(t_stack **a, t_stack **b, int flag, int
print);
int						call_push(t_stack **a, t_stack **b, int flag, int
print);
int						call_rotate(t_stack **a, t_stack **b, int flag, int
print);
int						call_rev_rotate(t_stack **a, t_stack **b, int flag, int
print);

/*
** sort for short arrays
*/

int						bubble_sort(t_stack *a, t_stack *b, int print);
int						bubble_sort_extra(t_stack **a, t_stack **b, t_stack
**second, t_trash t);
int						shaker_sort(t_stack *a, t_stack *b, int print);
int						selection_sort(t_stack *a, t_stack *b, int print);
int						selection_sort_push_min(t_stack **a, t_stack **b, int
*min, int print);
int						selection_sort_find_min(t_stack **a, t_stack **b, int
min, int print);
int						sort_three(t_stack **a, int print);
int						sort_three_extra(t_stack **a, int print);
int						five_sort(t_stack *a, t_stack *b, int print);
int						five_sort_extra(t_stack **a, t_stack **b, int print);

/*
** quick_sort
*/

void					first_quick_sort(t_stack **a, t_stack **b);
void					rotate_stack_b(t_stack **a, t_stack **b, int *rotate, \
int min);
void					rev_rotate_stack_b(t_stack **a, t_stack **b, \
int *rotate, int min);
int						rotate_or_push(t_stack **a, t_stack **b, int ref);

void					quick_sort(t_stack *a, t_stack *b);
void					quick_sort_extra(t_stack **a, t_stack **b, int flag);
void					rev_select_sort(t_stack **a, t_stack **b);
int						rev_quick_sort(t_stack **a, t_stack **b, int *flag);
int						find_next_value(t_stack *a, t_stack *b);

int						ft_is_it_sorted(t_stack *a);
int						is_sort_check(int *array, int start, int size);
int						find_placement(t_stack *tmp, int ref);
int						find_min(t_stack *tmp);
int						find_max(t_stack *tmp);
int						find_num(t_stack *tmp, int top, int flag);
int						find_spec_number(t_stack *a, int ref);
int						find_median(t_stack *a);

#endif
