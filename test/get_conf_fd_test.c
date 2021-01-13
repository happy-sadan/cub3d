/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conf_fd_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 03:30:08 by trcottam          #+#    #+#             */
/*   Updated: 2021/01/12 11:40:04 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define VALID_CFGPATH "valid.cub"
#define INVALID_CFGPATH "invalid.cub"
#define VALID_FD 42

FAKE_VALUE_FUNC_VARARG(int, open, const char *, int, ...);

int		open_custom_fake(const char *path, int oflag, va_list mode)
{
	(void)oflag;
	(void)mode;
	if (ft_strcmp(path, VALID_CFGPATH))
		return (-1);
	return (VALID_FD);
}

void	setUp(void)
{
	open_fake.custom_fake = open_custom_fake;
}

void	tearDown(void)
{
}

void	test_get_conf_fd_handles_valid_path(void)
{
	TEST_ASSERT_EQUAL(VALID_FD, get_conf_fd(VALID_CFGPATH));
}

void	test_get_conf_fd_handles_invalid_path(void)
{
	TEST_ASSERT_EQUAL(VALID_FD, get_conf_fd(INVALID_CFGPATH));
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_conf_fd_handles_valid_path);
	RUN_TEST(test_get_conf_fd_handles_invalid_path);
	return (UNITY_END());
}
