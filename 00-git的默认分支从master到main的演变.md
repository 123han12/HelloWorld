## 发现

一开始接触 Git 的时候，默认的分支名都为 `master` ，包括后续使用的时候也习惯于输入`master`进行各类操作。

而我最近发现，[Github](https://github.com/) 与 [Gitlab](https://about.gitlab.com/) 都开始使用 `main` 取代原先的 `master`
作为项目的默认主分支了，这是为什么呢？

## 起源 - “Black Lives Matter”

自2020年六月起，由于“Black Lives Matter”抗议活动持续发酵，而计算机行业中对`master`与`slave`这两个词的使用引起了部分人的反感。

在抗议声起、社会动荡加剧之时，更多的人认为这些包含历史文化因素的词汇已经过时，且应当被替换，于是多个开源项目开始采取行动替换冒犯性的术语，其中包括 PHPUnit 和 Curl、OpenZFS 等。

不仅仅是`master`与`slave`,还有许多相关的词汇如`whitelist`与`blacklist`都被计划更改为`allowList`与`denyList`。

正如 [ZDNet](https://www.zdnet.com/article/github-to-replace-master-with-main-starting-next-month/) 所说，继续使用这些带有种族色彩的词汇可能会延长种族歧视。一些学者在 2018 年的期刊上写道，“这些术语不仅反映了种族主义文化，而且还强化、合法化和延续了它。”

而 LinkedIn 的软件工程师 Gabriel Csapo 也在 Twitter 上表示，他也正在提出更新 Microsoft 内部库的请求，并删除任何带有种族歧视色彩的短语。

## 行动

在此背景下，一位Twitter网友的提议，而这一提议得到了GitHub CEO的支持。
![Twitter](https://pages.carm.cc/images/branch-main/una_kravets.png)

>  
>
> #### @Una Kravets
>
> 我很高兴将 GitHub 的默认分支结构从『master』改成『main』，我希望我们能和 @GitHub 一起以社区为单位来做这件事……
>
> #### @Nat Friedman
>
> 这是个好主意！ 我们正在朝这方面进行改进了！

于是自 2020年10月1日 开始，Github上所有的新库便都开始以 `main` 命名，并开始逐渐的将原先`master`为主分支的库修改为以`main`为主分支。

鉴于GitHub有4000多万用户、1亿多个存储库以及至少2800万个公共存储库，这是项艰巨的任务。 任何一个规划的失误都会导致Linux内核之类的项目代码无法访问。全球大批企业依赖Linux内核，一旦发生这类事件都可能引发灾难性的后果。

于是，GitHub又做了以下更改以确保万无一失：

- [更新了 GitHub.com](https://github.blog/changelog/2020-07-17-links-to-deleted-branches-now-redirect-to-the-default-branch/) 以直接重定向`master`分支到新的默认分支！

- [更新了 Github Pages](https://github.blog/changelog/2020-07-31-build-and-deploy-github-pages-from-any-branch-beta/) 以支持从任一分支进行部署

- 添加了用户、组织与企业设定

   

  以设定默认的分支名与新项目的默认分支名。

  - 需要注意的是，这些设定同时在 [GitHub.com](https://github.com/new) 与 [GitHub API](https://developer.github.com/v3/guides/getting-started/#create-a-repository) 生效。
  - [Git 2.28](https://github.blog/2020-07-27-highlights-from-git-2-28/#introducing-init-defaultbranch) 也添加了一个类似的设定 `init.defaultBranch`。

- [我们让重命名已有分支更加方便快捷了](https://github.com/github/renaming#rename-existing)

## 参与

如果还是习惯于使用 `master` 分支，那么大可不用更改继续使用下去。

若想要支持相关的行动，则可以跟随以下的操作将`master`分支无损迁移到`main`分支。

### 本地修改分支

1. 首先将`master`分支移到`main`分支下

```
git branch -m master main
```

1. 随后将新命名的分支`main`推送到远程库中

```
git push -u origin main
```

1. 再将HEAD指向`main`分支

```
git symbolic-ref refs/remotes/origin/HEAD refs/remotes/origin/main
```

1. 最后删除远程库中旧的`master`分支即可

```
git push origin --delete master
```

### 在 GitHub 上修改默认分支

用户、组织和企业可以在以下地址修改默认分支名。

- 用户 `https://github.com/settings/repositories`
- 组织所有者 `https://github.com/organizations/<组织名>/settings/repository-defaults`
- 企业管理员 `https://github.com/enterprises/<企业名>/settings/member_privileges`

![Settings](https://pages.carm.cc/images/branch-main/settings.png)

## 参考文献

- < [Github Renaming](https://github.com/github/renaming) >
- < [GitHub to replace ‘master’ with ‘main’ starting next month](https://www.zdnet.com/article/github-to-replace-master-with-main-starting-next-month/) >
- < [Why GitHub renamed its master branch to main](https://www.theserverside.com/feature/Why-GitHub-renamed-its-master-branch-to-main) >