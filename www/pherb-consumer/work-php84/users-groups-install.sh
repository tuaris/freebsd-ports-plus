if [ -n "${PKG_ROOTDIR}" ] && [ "${PKG_ROOTDIR}" != "/" ]; then
  PW="/usr/sbin/pw -R ${PKG_ROOTDIR}"
else
  PW=/usr/sbin/pw
fi
echo "===> Creating groups"
if ! ${PW} groupshow pherb >/dev/null 2>&1; then
  echo "Creating group 'pherb' with gid '803'"
  ${PW} groupadd pherb -g 803 || exit $?
else
  echo "Using existing group 'pherb'"
fi
echo "===> Creating users"
if ! ${PW} usershow pherb >/dev/null 2>&1; then
  echo "Creating user 'pherb' with uid '803'"
  ${PW} useradd pherb -u 803 -g 803  -c "Pherb Daemon" -d /nonexistent -s /usr/sbin/nologin || exit $?
else
  echo "Using existing user 'pherb'"
fi
