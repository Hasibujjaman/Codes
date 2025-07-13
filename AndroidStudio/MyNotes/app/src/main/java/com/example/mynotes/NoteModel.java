package com.example.mynotes;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "My_Notes")
public class NoteModel {
    @PrimaryKey(autoGenerate = true)
    private int id;
    private String title;
    private String note;



    public NoteModel(String title, String note) {
        this.title = title;
        this.note = note;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
