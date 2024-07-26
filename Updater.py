import requests
import sys

try:
    code = requests.get('https://raw.githubusercontent.com/IsusRamzy/SimpleDuino/master/SimpleDuino.cpp').text
    version = code.split('\n')[0] # First Line
    with open('SimpleDuino.cpp') as file:
        current_version = file.read().split('\n')[0]
    if current_version == version:
        print('SimpleDuino is already the latest version.')
        sys.exit(0)
    if 'Stable' in version:
        with open("SimpleDuino.cpp", 'w') as file:
            file.write(code)
        print(f'SimpleDuino Updated from {current_version} to {version}')
    elif 'Beta' in version:
        okay = input("This is a beta version, not very stable.\nUpgrade? (Y/n):").lower()
        if okay == 'n':
            print('UPGRADE ABORTED')
        elif okay == 'y':
            with open("SimpleDuino.cpp", 'w') as file:
                file.write(code)
            print(f'SimpleDuino Updated from {current_version} to {version}')
    elif 'Dev' in version:
        okay = input("This is a development version. It's even less stable than beta versions. It may completely break SimpleDuino.\nDevelopers use it to test upgrades before making them stable. Upgrade? (Y/n):").lower()
        if okay == 'n':
            print('UPGRADE ABORTED')
        elif okay == 'y':
            with open("SimpleDuino.cpp", 'w') as file:
                file.write(code)
            print(f'SimpleDuino Updated from {current_version} to {version}')
except requests.ConnectionError:
    print('CONNECTION FAILED')
    sys.exit(1)