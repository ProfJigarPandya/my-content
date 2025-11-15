Fedora

To list running/waiting jobs
systemctl list-jobs


systemctl list-units -t service --all  | wc -l
242

Active service
systemctl list-units -t service

/usr/lib/systemd/systemd --test --system --unit=multi-user.target

Courtesy: https://docs.fedoraproject.org/en-US/quick-docs/debug-systemd-problems/
