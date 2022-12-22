#!/usr/bin/python3
"""Module count_words"""
import requests
import sys


def count_words(subreddit, word_list, kw_cont={}, next_pg=None, reap_kw={}):
    """
    Query the Reddit API, parse titles of all hot articles and print a
    sorted count of given keywords
    Args:
        subreddit (str): subreddit to search in
        word_list (str): list of words to search for
        kw_count (dict): Creates dict to store strings
        next_pg (str): next page
        reap_kw (dict): Creates dict to store strings
    """
    headers = {"User-Agent": "nildiert"}
    if next_pg:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json?after=' + next_pg, headers=headers)
    else:
        subr = requests.get('https://reddit.com/r/' + subreddit + '/hot.json',
                            headers=headers)
    if subr.status_code == 404:
        return
    if kw_cont == {}:
        for word in word_list:
            kw_cont[word] = 0
            reap_kw[word] = word_list.count(word)
    subr_dict = subr.json()
    subr_data = subr_dict['data']
    next_pg = subr_data['after']
    subr_posts = subr_data['children']
    for post in subr_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in kw_cont:
                if w.lower() == key.lower():
                    kw_cont[key] += 1
    if next_pg:
        count_words(subreddit, word_list, kw_cont, next_pg, reap_kw)
    else:
        for key, val in reap_kw.items():
            if val > 1:
                kw_cont[key] *= val
        sorted_abc = sorted(kw_cont.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
