#ifndef __ITEMINFO_H_
#define __ITEMINFO_H_

#include "defines.h"

#include "STLMap.h"
#include "N3TableBase.h"

using namespace std;

//-----------------------------------------------------------------------------
class ItemInfo {
private:
	static vector<class ItemInfo> _items;
	static vector<string> _mesh_files_in_dir;
	static CSTLMap<_ITEM_TABLE> _db_item_info;
	static CN3TableBase<__TABLE_ITEM_BASIC>* _tbl_item_info;

public:
	static bool LoadInformation(void);
	static void CreateItemsFromInfo(void);
	static class ItemInfo* GetItem(int i);
	static int GetNumTblItems(void);

private:
	int m_tbl_ind;
	e_ItemType m_type;
	map<e_Race, int> mesh_file_ind_for_race;

private:
	void setMeshFileForRace(e_Race race, bool check_type = true);

public:
	__TABLE_ITEM_BASIC tbl_info;

public:
	e_ItemType getItemType(void);
	string getItemMeshFileForRace(e_Race race);
	void setItemMeshFileForRace(e_Race race, string& filename);

public:
	ItemInfo(void);
	~ItemInfo(void);
};

#endif
