/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:05:01 by emagueri          #+#    #+#             */
/*   Updated: 2024/02/04 14:49:24 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# define BUFFER_SIZE 10

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	check_args(char const *av[], t_stack **stack_a);
void	free_tab(char **res);
int		check_dup(t_stack **stack_a, char **arrs, int nbr);
int		is_sorted(t_stack *stk);

void	print_error_exit(void);
void	free_print_error_exit(char *str);

int		is_sorted(t_stack *stk);

void	sort_tree(t_stack **stack_a, t_stack **stack_b);
int		sort_four(t_stack **stack_a, t_stack **stack_b);
int		sort_five(t_stack **stack_a, t_stack **stack_b);

int		sa(t_stack **head);
int		sb(t_stack **head_b);
int		ss(t_stack **head_a, t_stack **head_b);

int		ra(t_stack **head_a);
int		rb(t_stack **head_b);
int		rr(t_stack **head_a, t_stack **head_b);

int		rra(t_stack **head_a);
int		rrb(t_stack **head_b);
int		rrr(t_stack **head_a, t_stack **head_b);

int		pb(t_stack **stk_b, t_stack **stk_a);
int		pa(t_stack **stk_a, t_stack **stk_b);

int		stk_size(t_stack *lst);
void	stk_clear(t_stack **lst);
void	stk_add_front(t_stack **lst, t_stack *new);
void	stk_add_back(t_stack **lst, t_stack *new);
t_stack	*stk_new(int content, int index);
t_stack	*stk_last(t_stack *lst);
t_stack	*stk_before_last(t_stack *stk);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		chunks_sort(t_stack **stack_a, t_stack **stack_b);
int		max_pos(t_stack *stk);
int		max_pos_sec(t_stack *stk);
int		abs(int n);
int		cost_pos(int pos, int size_stack);
int		count_cost(int pos, int size);

char	*get_next_line(int fd);
void	free_it(char *str);
char	*ft_strjoin_nl(char const *s1, char const *s2, int lens2);
int		ft_strlen_nl(const char *str);

int		swap_first_two(t_stack **head);
int		rotate(t_stack **head);
int		reverse_rotate(t_stack **head);
int		push(t_stack **stk_a, t_stack **stk_b);

void	swap_check(t_stack **stack_a, t_stack **stack_b, char *instr);
void	rotate_check(t_stack **stack_a, t_stack **stack_b, char *instr);
void	reverse_check(t_stack **stack_a, t_stack **stack_b, char *instr);
void	push_check(t_stack **stack_a, t_stack **stack_b, char *instr);

#endif