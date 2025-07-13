package com.example.mynotes;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.DiffUtil;
import androidx.recyclerview.widget.ListAdapter;
import androidx.recyclerview.widget.RecyclerView;

public class RecyclerViewAdapter extends ListAdapter<NoteModel, RecyclerViewAdapter.ViewHolder> {

    public RecyclerViewAdapter(){
        super(CALLBACK);
    }
    private static final DiffUtil.ItemCallback<NoteModel> CALLBACK = new DiffUtil.ItemCallback<NoteModel>() {
        @Override
        public boolean areItemsTheSame(@NonNull NoteModel oldItem, @NonNull NoteModel newItem) {
            return oldItem.getId() == newItem.getId();
        }

        @Override
        public boolean areContentsTheSame(@NonNull NoteModel oldItem, @NonNull NoteModel newItem) {
            return oldItem.getTitle().equals(newItem.getTitle()) && oldItem.getNote().equals(newItem.getNote());
        }
    };

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.recycler_items, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        NoteModel noteModel = getItem(position);
        holder.txtTitle.setText(noteModel.getTitle());
        holder.txtNote.setText(noteModel.getNote());

    }
    public NoteModel getNote(int p){
        return getItem(p);
    }

    public class ViewHolder extends RecyclerView.ViewHolder{
        TextView txtTitle,txtNote;
        LinearLayout llRow;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            txtNote = itemView.findViewById(R.id.txtNote);
            txtTitle = itemView.findViewById(R.id.txtTitle);
            llRow = itemView.findViewById(R.id.llRow);

        }
    }

}
