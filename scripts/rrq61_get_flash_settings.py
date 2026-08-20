import os
from collections import namedtuple

target_path = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir))
target_file = ['rafw_gen/hal_data.c' , "rafw_gen/common_data.c"]
searchword_list = ['ctrlmode_reg','burstcmda_reg','burstcmdb_reg','flash_config']
resultword_list = [0,0,0,0]

FSP_regvVlues = namedtuple('FSP_regvVlues',['ctrlmode_reg', 'burstcmda_reg', 'burstcmdb_reg', 'flash_config'])

def get_reg_setting():
    for target_file_name in target_file:
        file_path = os.path.join(target_path, target_file_name)
        try:
            with open(file_path) as f:
                search_number = 0
                while True:
                    line = f.readline()
                    if not line:
                        f.close()
                        break
                    if searchword_list[search_number] in line:
                        reg_name = searchword_list[search_number]
                        workd_str                      = line.replace('#define ', '').replace(' ', '').replace(reg_name, '').replace('\r', '').replace('\n', '')
                        if reg_name != 'flash_config':
                            resultword_list[search_number] = int(workd_str, 0)
                        if reg_name == 'flash_config':
                            workd_str = workd_str.replace('0x', '')
                            resultword_list[search_number] = workd_str
                        search_number += 1
                        if search_number == len(searchword_list):
                            f.close()
                            break
                result_len = len(searchword_list)
                if result_len == search_number:
#                   print('File containing settings:' + target_file_name)
                    print('\033[34m' + 'External flash settings are based on FSP.' + '\033[0m')
                    f.close()
                    break
                else:
                    #If any setting value is not found, return 0.
                    resultword_list[3] = '00'
                    for i in range(len(resultword_list)-1):
                        resultword_list[i] = 0
        except Exception as e:
            print('\033[31m' + target_file_name + " is not exist." +'\033[0m')
            print(e)
            print(type(e))
            resultword_list[3] = '00'
            for i in range(len(resultword_list)-1):
                resultword_list[i] = 0

    fsp_reg = FSP_regvVlues(ctrlmode_reg  = resultword_list[0], 
                            burstcmda_reg = resultword_list[1], 
                            burstcmdb_reg = resultword_list[2],
                            flash_config  = bytes.fromhex(resultword_list[3]))
    if fsp_reg.ctrlmode_reg == 0:
        print('\033[32m' + 'External flash settings are default.' + '\033[0m')
#    else:
#        print('ctrlmode_reg  = '+f'{fsp_reg.ctrlmode_reg:#010x}')
#        print('burstcmda_reg = '+f'{fsp_reg.burstcmda_reg:#010x}')
#        print('burstcmdb_reg = '+f'{fsp_reg.burstcmdb_reg:#010x}')
#        print('flash_config  = '+f'{fsp_reg.flash_config}')
    return fsp_reg
